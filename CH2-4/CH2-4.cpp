#include <vector>
#include <string>
#include <iostream>

// PotionRecipe class 정의
class PotionRecipe
{
public:
    // 멤버변수를 초기화
    
    PotionRecipe(const std::string& potionName, const std::string& coreIngredient)
        : potionName_(potionName)
        , coreIngredient_(coreIngredient)
    {

    }

    // 멤버 변수에 접근하기 위한 Getter 함수
    const std::string& GetPotionName() const
    {
        return potionName_;
    }
   
    const std::string& GetCoreIngredient() const
    {
        return coreIngredient_;
    }

private:
    std::string potionName_;
    std::string coreIngredient_;
};



// AlchemyWorkshop class 정의
class AlchemyWorkshop
{
public:
    // 새로운 레시피를 recipes 벡터에 추가, push_back()
    void AddRecipe(const std::string& potionName, const std::string& coreIngredient)
    {
        recipes_.push_back(PotionRecipe(potionName, coreIngredient)); //Potion의 객체를 만들어서 추가하겠다
    }// 모든 레시피의 이름과 핵심 재료 출력
    // for (const PotionRecipe& r : recipes_) <- range-for 구문
    void DisplayAllRecipes() const
    {
    
        for (const PotionRecipe& r : recipes_)//recipes 안의 모들 레시피들을 r이라 부르고 꺼내 보겠다
        {
            std::cout << r.GetPotionName() << "/" << r.GetCoreIngredient() << std::endl;
        }
    }

    // 이름으로 레시피 검색(range-for, == 를 활용해보자)//이게 포션의 이름이었구나;;
    // - 예외처리 : 동일한 이름이 없을 경우 어떻게 처리할지는 자유
    // PotionRecipe("NONE", "NONE"); ? 
    //같은 이름의 물약 없음
    PotionRecipe SearchRecipeByName(const std::string& name) const
    {
        //포션레시피를 r이라고 부르고 벡터 안의 모든 레시피를 다 찾아보겠다
        for (const PotionRecipe& r: recipes_)
        {
            if(r.GetPotionName() == name)
            {
                //std::cout << r << endl; main에서 출력한다 여기서 출력할 필요 없이 값만 반환해라
                return r;
            }
            /*{
            else
                return PotionRecipe("NONE", "NONE");
            }
            */

        }

        return PotionRecipe("NONE", "NONE");
       
    }

    // 특정 재료를 사용하는 모든 레시피 검색(range-for, == 를 활용해보자)
    // - 결과가 여러 개일 수 있음
    // - 예외처리 : 결과가 없을 경우 어떻게 처리할지는 자유(위와 비슷하게 해보자)
    //중복될 수가 있었네
    std::vector<PotionRecipe> SearchRecipeByIngredient(const std::string& ingredient) const//문자열을 매개변수로 갖는 벡터를 반환하는 함수 정의?
    {
        std::vector<PotionRecipe> sameingredient_;//재료 중복된 레시피들을 모을 벡터
        
        for (const PotionRecipe& r : recipes_)
        {
            if(r.GetCoreIngredient() == ingredient)
            {
                sameingredient_.push_back(r);
            }
            /*else
            {
                return PotionRecipe("NONE", "NONE");
            }*/
        }

        return sameingredient_;
    }

private:
    std::vector<PotionRecipe> recipes_;//클래스 전체에 벡터 선언을 해둔건가? 왜지?
    //PotionRecipe 객체를 모은 벡터

};

int main()
{
    AlchemyWorkshop workshop;

    // 레시피 추가
    workshop.AddRecipe("Healing Potion", "Herb");
    workshop.AddRecipe("Mana Potion", "Magic Water");
    workshop.AddRecipe("Stamina Potion", "Herb");
    workshop.AddRecipe("Revival Potion", "Blood");
    workshop.AddRecipe("Slime Potion", "Slime");
    workshop.AddRecipe("Sturn Potion", "TaranTula");
    workshop.AddRecipe("Sticky Potion", "Frog");
    workshop.AddRecipe("Smaller Potion", "Mushroom");
    workshop.AddRecipe("Bigger Potion", "Mushroom");
    workshop.AddRecipe("Older Potion", "Frog");
    workshop.AddRecipe("TimeSlip Potion", "Dragon's Tear");
    workshop.AddRecipe("Angry Potion", "Assignment Paper");
    workshop.AddRecipe("Happy Potion", "Money");

    // 전체 레시피 출력
    workshop.DisplayAllRecipes();

    // 이름으로 레시피 검색
    PotionRecipe recipe = workshop.SearchRecipeByName("Mana Potion");
    std::cout << "검색된 레시피: "
        << recipe.GetPotionName() << std::endl;

    // 재료로 레시피 검색
    std::vector<PotionRecipe> herbRecipes =
        workshop.SearchRecipeByIngredient("Herb");

    std::cout << "Herb를 사용하는 레시피 수: "
        << herbRecipes.size() << std::endl;

    return 0;
}
