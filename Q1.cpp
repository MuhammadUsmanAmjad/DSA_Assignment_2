//#include <iostream>
//using namespace std;
//void input(int *&arr, int &size)
//{
//    cout << "Enter numbers -1 to Stop:-";
//    int num = 0;
//    cin >> num;
//    while (num != -1)
//    {
//        if (size == 0 && num != 1 && num <= 9)
//        {
//            arr = new int[++size];
//            arr[0] = num;
//        }
//        else if (num != 1 && num <= 9)
//        {
//            int *temp = new int[size + 1];
//            for (int i = 0; i < size; i++)
//                temp[i] = arr[i];
//            temp[size] = num;
//            size++;
//            delete[] arr;
//            arr = temp;
//        }
//        cin >> num;
//    }
//}
//
//void store_aplhabets(string &str, int num)
//{
//    switch (num) {
//        case 2:
//            str = "ABC";
//            break;
//        case 3:
//            str = "DEF";
//            break;
//        case 4:
//            str = "GHI";
//            break;
//        case 5:
//            str = "JKL";
//            break;
//        case 6:
//            str = "MNO";
//            break;
//        case 7:
//            str = "PQRS";
//            break;
//        case 8:
//            str = "TUV";
//            break;
//        case 9:
//            str = "WXYZ";
//            break;
//    }
//}
//void get_alphabets(string *str, int *arr, int size)
//{
//    static int i = 0;
//    if (i == size)
//        return;
//    store_aplhabets(str[i], arr[i]);
//    ++i;
//    get_alphabets(str, arr, size);
//}
//void print(string *str, int *arr, char *s, int str_idx, int s_idx, int size)
//{
//    if (str_idx == size)
//    {
//        s[s_idx] = 0;
//        cout << s << " ";
//        return;
//    }
//    for (int k = 0; k < str[str_idx].size(); k++)
//    {
//        s[s_idx] = str[str_idx][k];
//        print(str, arr, s, str_idx + 1, s_idx + 1, size);
//    }
//    cout<<endl;
//}
//int main()
//{
//    int size = 0;
//    int *num_array;
//    input(num_array, size);
//    for (int i = 0; i < size; i++)
//        cout << num_array[i] << "  ";
//    string str_chars[size];
//    get_alphabets(str_chars, num_array, size);
//    cout << endl;
//    char ch[1000];
//    print(str_chars, num_array, ch, 0,0,size);
//    return 0;
//}
