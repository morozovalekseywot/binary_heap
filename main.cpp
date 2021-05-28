#include "functions.hpp"
#include "Set_Array.hpp"
#include "Set_vector.hpp"
#include "tests.hpp"
int main()
{
    ofstream file("Compare.txt", ios_base::trunc);
    file << "Function name\ntime array time Linked_List\n";
    file.close();
    write_results(test_create(1e4),"Compare.txt","Test_Create");
    write_results(test_insert(1e4),"Compare.txt","Test_Insert");
    write_results(test_search(1e4),"Compare.txt","Test_Search");
    //write_results(test_remove(1e3),"Compare.txt","Test_Remove");
    write_results(test_sum(3e4),"Compare.txt","Test_Sum");
    write_results(test_subtraction(1e4),"Compare.txt","Test_Subtraction");
}
