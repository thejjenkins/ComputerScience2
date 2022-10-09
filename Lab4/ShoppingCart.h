#include <string>
#include <vector>
using namespace std;

class ShoppingCart {
    public:
    string GetCustomerName() const;
    string GetDate() const;
    void AddItem(); //FIXME
    void RemoveItem(); //FIXME
    void ModifyItem(); //FIXME
    int GetNumItemsInCart(); //FIXME
    int GetCostOfCart(); //FIXME
    void PrintTotal(); //FIXME
    string PrintDescriptions(); //FIXME
    private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};