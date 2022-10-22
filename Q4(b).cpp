//#include <iostream>
//#include <stdlib.h>
//#include <cstdlib>
//#include <unistd.h>
//#include <vector>
//#include <queue>
//using namespace std;
//class Receiver
//{
//    vector<queue<int> *> sqn;
//
//public:
//    Receiver()
//    {
//        sqn.reserve(5);
//        for (int i = 0; i < 5; i++)
//            sqn[i] = new queue<int>();
//    }
//    void add_request(int rid, int req_no)
//    {
//        sqn[rid]->push(req_no);
//    }
//    void print_queue(queue<int> q)
//    {
//        if (q.empty())
//        {
//            cout << endl;
//            return;
//        }
//        cout << q.front() << " ";
//        q.pop();
//        print_queue(q);
//    }
//    void print_all_Queues()
//    {
//
//        for (int i = 0; i < 5; i++)
//            print_queue(*sqn[i]);
//    }
//    void service_request_at_resource(int rid) {
//        int data = sqn[rid]->front();
//        this->sqn[rid]->pop();
//        for (int i = 0; i < data / 100; i++) {
//            sleep(1);
//            this->add_request(rand() % 5, rand() % 1000);
//        }
//    }
//    bool isEmpty()
//    {
//        for(int i=0;i<5;i++)
//            if(sqn[i]->empty())
//                return true;
//        return false;
//    }
//    };
//int main()
//{
//    time(0);
//    srand(time(0));
//    Receiver *res = new Receiver();
//    res->add_request(0, 250);
//    res->add_request(0, 100);
//    res->add_request(2, 300);
//    res->add_request(1, 400);
//    res->add_request(1, 90);
//    res->add_request(2, 40);
//    res->add_request(4, 200);
//    res->add_request(3, 600);
//    res->print_all_Queues();
//    while(1)
//    {
//        res->service_request_at_resource(rand() % 5);
//        cout << "Request Served at Random Resource And Updated List is:-\n";
//        res->print_all_Queues();
//        system("clear");
//        if(res->isEmpty())
//            break;
//    }
//
//    return 0;
//}