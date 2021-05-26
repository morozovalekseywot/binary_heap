#include "Set.h"

int main()
{
    vector<int> vec = {2, 4, 3, 7, 6, 5, 3, 2};
    Heap<int> heap(vec);
    for (int i = 0; i < heap.data.size(); i++)
        cout << heap.data[i] << " ";
    cout << "\n";
    //cout << heap.search(1);
    heap.insert(10);
    heap.insert(8);
    heap.insert(9);
    heap.insert(16);
    heap.insert(11);
    heap.insert(12);
    par_node(heap);

    //heap.remove(10);
    auto b = heap.sub_heap(10);
    par_node(b);
    Heap<int> sub({10, 8, 9, 7});
    par_node(sub);
    //sub.printNLR2(0,cout);
    cout << "\n";
    Set<int> Set_b = Set<int>({1, 8, 10, 2});
    Set<int> Set_a = Set<int>({11, 4, 8, 1});
    cout<<"Set a: "<<Set_a<<"\n";
    cout<<"Set b: "<<Set_b<<"\n";
    //cout<<heap.size()<<" "<<Set_a.size();
    Set<int> Set_sum = Set_a + Set_b;
    cout <<"Size of Set_sum: " <<Set_sum.size() << ", Set: " << Set_sum<<"\n";
    Set<int> Set_diff = Set_a - Set_b;
    cout <<"Size of Set_diff: " <<Set_diff.size() << ", Set: " << Set_diff<<"\n";
    Set<int> Set_in = Set_a * Set_b;
    cout <<"Size of Set_in: " <<Set_in.size() << ", Set: " << Set_in<<"\n";
    Set<int> Set_str = Set<int>("12 7328 92 2 749 3286 2398 234023",1);
    cout<<Set_str;
    //cout<<Set_a-Set_b;
    //cout << b.search_heap(sub);
}
