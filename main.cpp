#include "functions.hpp"
#include "Set_Array.hpp"
#include "tests.hpp"

int main()
{
    string str;
    int s1 = 0;
    while (s1 != 4)
    {
        cout << endl << "Select an action:" << endl << "1 - create set" << endl << "2 - create heap" << endl << "3 - run tests" << endl << "4 - exit" << endl;
        cin >> s1;
        switch (s1)
        {
            case 1:
            {
                cout << "Write an items:" << endl;
                getline(cin, str);
                getline(cin, str);
                Set_Node<int> st = setFromString(str);
                int s2 = -1, item;
                while (s2 != 0)
                {
                    cout << endl << "Your set:" << endl;
                    st.print(cout);
                    cout << endl << endl << "Select the action with set:" << endl
                         << "1 - insert element" << endl
                         << "2 - search element" << endl
                         << "3 - remove element" << endl
                         << "4 - intersect set" << endl
                         << "5 - unite set" << endl
                         << "6 - subtract set" << endl
                         << "7 - search subset" << endl
                         << "0 - exit" << endl;
                    cin >> s2;
                    switch (s2)
                    {
                        case 1:
                        {
                            cout << "item: ";
                            cin >> item;
                            st.insert(item);
                            break;
                        }
                        case 2:
                        {
                            cout << "item: ";
                            cin >> item;
                            if (st.search(item)) cout << "TRUE";
                            else cout << "FALSE";
                            cout << endl;
                            break;
                        }
                        case 3:
                        {
                            cout << "item: ";
                            cin >> item;
                            st.remove(item);
                            break;
                        }
                        case 4:
                        {
                            cout << "Write an items:" << endl;
                            getline(cin, str);
                            getline(cin, str);
                            Set_Node<int> new_st = setFromString(str);
                            cout << endl << "New set:" << endl;
                            new_st.print(cout);
                            cout << endl;
                            st = st.intersection(new_st);
                            break;
                        }
                        case 5:
                        {
                            cout << "Write an items:" << endl;
                            getline(cin, str);
                            getline(cin, str);
                            Set_Node<int> new_st = setFromString(str);
                            cout << endl << "New set:" << endl;
                            new_st.print(cout);
                            cout << endl;
                            st = st.unification(new_st);
                            break;
                        }
                        case 6:
                        {
                            cout << "Write an items:" << endl;
                            getline(cin, str);
                            getline(cin, str);
                            Set_Node<int> new_st = setFromString(str);
                            cout << endl << "New set:" << endl;
                            new_st.print(cout);
                            cout << endl;
                            st = st.subtraction(new_st);
                            break;
                        }
                        case 7:
                        {
                            cout << "Write an items:" << endl;
                            getline(cin, str);
                            getline(cin, str);
                            Set_Node<int> new_st = setFromString(str);
                            cout << endl << "New set:" << endl;
                            new_st.print(cout);
                            cout << endl << endl;
                            if (st.include(new_st)) cout << "TRUE";
                            else cout << "FALSE";
                            cout << endl;
                            break;
                        }
                        case 0:
                        {
                            break;
                        }
                        default:
                        {
                            printf("Enter a number from the list!\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                cout << "Write an items:" << endl;
                getline(cin, str);
                getline(cin, str);
                Heap_Node<int> hp = heapFromString(str);
                int s2 = -1, item;
                while (s2 != 0)
                {
                    cout << endl << "Your heap:" << endl;
                    hp.NLR(cout);
                    cout << endl << endl << "Select the action with heap:" << endl
                         << "1 - insert element" << endl
                         << "2 - search element" << endl
                         << "3 - remove element" << endl
                         << "4 - make subheap" << endl
                         << "5 - search subheap" << endl
                         << "6 - trip a graph" << endl
                         << "0 - exit" << endl;
                    cin >> s2;
                    switch (s2)
                    {
                        case 1:
                        {
                            cout << "item: ";
                            cin >> item;
                            hp.insert(item);
                            break;
                        }
                        case 2:
                        {
                            cout << "item: ";
                            cin >> item;
                            if (hp.search(item)) cout << "TRUE";
                            else cout << "FALSE";
                            cout << endl;
                            break;
                        }
                        case 3:
                        {
                            cout << "item: ";
                            cin >> item;
                            hp.remove(item);
                            break;
                        }
                        case 4:
                        {
                            cout << "item: ";
                            cin >> item;
                            hp = hp.subHeap(item);
                            break;
                        }
                        case 5:
                        {
                            cout << "Write an items:" << endl;
                            getline(cin, str);
                            getline(cin, str);
                            Heap_Node<int> new_hp = heapFromString(str);
                            cout << endl << "New heap:" << endl;
                            new_hp.NLR(cout);
                            cout << endl;
                            if (hp.searchHeap(new_hp)) cout << "TRUE";
                            else cout << "FALSE";
                            cout << endl;
                            break;
                        }
                        case 6:
                        {
                            int s3 = -1;
                            while (s3 != 0)
                            {
                                cout << endl << "Select:" << endl
                                     << "1 - NLR" << endl
                                     << "2 - NRL" << endl
                                     << "3 - LRN" << endl
                                     << "4 - LNR" << endl
                                     << "5 - RLN" << endl
                                     << "6 - RNL" << endl
                                     << "0 - exit" << endl;
                                cin >> s3;

                                switch (s3)
                                {
                                    case 1:
                                    {
                                        hp.NLR(cout);
                                        s3 = 0;
                                        break;
                                    }
                                    case 2:
                                    {
                                        hp.NRL(cout);
                                        s3 = 0;
                                        break;
                                    }
                                    case 3:
                                    {
                                        hp.LRN(cout);
                                        s3 = 0;
                                        break;
                                    }
                                    case 4:
                                    {
                                        hp.LNR(cout);
                                        s3 = 0;
                                        break;
                                    }
                                    case 5:
                                    {
                                        hp.RLN(cout);
                                        s3 = 0;
                                        break;
                                    }
                                    case 6:
                                    {
                                        hp.RNL(cout);
                                        s3 = 0;
                                        break;
                                    }
                                    case 0:
                                    {
                                        break;
                                    }
                                    default:
                                    {
                                        printf("Enter a number from the list!\n");
                                        break;
                                    }
                                }
                            }
                            cout << endl;
                            break;
                        }
                        case 0:
                        {
                            break;
                        }
                        default:
                        {
                            printf("Enter a number from the list!\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                const string file_name = "logs.txt";

                ofstream file(file_name, ios_base::trunc);
                file.close();
                int n = 1e4;
                write_results(test_create(n), file_name, "Test_Create");
                write_results(test_insert(n), file_name, "Test_Insert");
                write_results(test_search(n), file_name, "Test_Search");
                write_results(test_include(n), file_name, "Test_Include");
                write_results(test_sum(n), file_name, "Test_Sum");
                write_results(test_subtraction(n), file_name, "Test_Subtraction");
                write_results(test_intersection(n), file_name, "Test_Intersection");

                cout << "Tests successfully saved to " << file_name << endl;
                break;
            }
            case 4 :
            {
                break;
            }
            default:
            {
                cout << "Enter a number from the list!" << endl;
                break;
            }
        }
    }
    return 0;
}
