#include <iostream>
using namespace std;

class LinkedList {
    private:
        class ListNode {
            public:
                int data;
                ListNode* next;

                ListNode(int d)
                {
                    data = d;
                    next = NULL;
                }
            };
        
        ListNode* head;
    public:
        LinkedList()
        {
            head = NULL;
        }

        ~LinkedList()
        {
            //implement by yourself
        }

        void append(int d)
        {
            if(head==NULL)
            {
                head = new ListNode(d);
                return;
            }
            ListNode* tmp = head;
            while(tmp->next!=NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = new ListNode(d);
        }

        void display()
        {
            ListNode* tmp = head;
            while(tmp!=NULL)
            {
                cout<<tmp->data<<endl;
                tmp = tmp->next;
            }
        }

        int count()
        {
            ListNode* tmp = head;
            int count = 0;
            while(tmp!=NULL)
            {
                count += 1;
                tmp = tmp->next;
            }
            return count;
        }

        void erase(int d)
        {
            if(head->data==d)
            {
                ListNode* junk = head;
                head = head->next;
                delete junk;
                return;
            }


            ListNode* tmp = head;

            while(tmp!=NULL && tmp->next!=NULL && tmp->next->data!=d)
            {
                tmp = tmp->next;
            }

            if(tmp!=NULL)
            {
                ListNode* junk = tmp->next;
                tmp->next = tmp->next->next;
                delete junk;
            }
        }
        

        void insertBefore(int d, int e)
        {
            if(head==NULL)
            {
                return;
            }

            if(head->data==e)
            {
                ListNode* tmp = new ListNode(d);
                tmp->next = head;
                head = tmp;
                return;
            }

            ListNode* tmp = head;
            while(tmp!=NULL && tmp->next->data!=e)
            {
                tmp = tmp->next;
            }

            if(tmp!=NULL)
            {
                ListNode* nn = new ListNode(d);
                nn->next = tmp->next;
                tmp->next = nn;
            }
            
        }

        void getFirstNode()
        {
            cout<<head->data<<endl;  //first node
            cout<<head->next->data<<endl; //second node
            cout<<head->next->next->data<<endl; //third node
        }
};

int main()
{
    LinkedList c;
    
    c.append(19);
    c.append(23);
    c.append(49);
    c.append(1299);
    //c.erase(19);
   
    c.insertBefore(3333, 49);
    
    c.display();
   
    cout<<"Count: "<<c.count()<<endl;
    return 0;
}
