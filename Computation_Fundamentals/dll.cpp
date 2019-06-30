// Nick Michael
// Doubly Linked List

#include <iostream>
#include <string>
#include <memory>

struct Node_t
{
    std::shared_ptr<Node_t> next, prev;
    std::string data;

    Node_t()
    {
        next = NULL, prev = NULL;
    }
    Node_t(const std::string dat)
    {
        next = NULL, prev = NULL;
        data = dat;
    }
    ~Node_t()
    {
        std::cout << "Remove: " << data << std::endl;
        // prints message when object is destroyed
    }
};

class dll_t
{
  private:
    std::shared_ptr<Node_t> L = std::make_unique<Node_t>("");
    // First element in doubly linked list

  public:
    void insert(const std::string str_val)
    {
        std::shared_ptr<Node_t> p = std::make_shared<Node_t>(str_val);
        p->next = L->next;
        p->prev = L;
        // Insert p into list

        if (L->next != NULL)
            (L->next)->prev = p;
        L->next = p;
        // Point old pointers to p

        std::cout << "insert: " << L->next->data << std::endl;
    }

    void next()
    {
        if (L->next != NULL)
            L = L->next;
        // Move L to next value in list if next is not NULL
        // Else do nothing

        std::cout << "next" << std::endl;
    }

    void prev()
    {
        if (L->prev != NULL)
            L = L->prev;
        // Move L to prev value in list if prev is not NULL
        // Else do nothing

        std::cout << "prev" << std::endl;
    }

    void remove()
    {
        if (L->next != NULL)
        {
            if (L->next->next != NULL)
                (L->next->next)->prev = L;
            L->next = L->next->next;
        }
        /* node in linked list will be destroyed automatically  *
         * destructor called after reference count = 0.         *
         * As proof, "remove: <string>" is printed to std::cout *
         * only from the "Node_t" destructor.                   */

        else
            std::cout << "remove:" << std::endl;
        // do nothing if already at the end of linked list
    }

    friend std::ostream& operator<<(std::ostream& os, dll_t& list)
    {
        std::shared_ptr<Node_t> p = list.L;
        u_int ref_c = 0;
        // create a shared pointer and ref count to navigate list

        while (p->prev != NULL)
        {
            p = p->prev;
            ++ref_c;
        }
        // navigate to head of list keeping track of L location

        os << "\t\t<";
        while (ref_c > 0)
        {
            os << " " << p->data;
            p = p->next;
            --ref_c;
        }
        // print elements in list until reference count hits zero

        os << " |" << p->data;
        p = p->next;
        // print additional vertical bar to track location on L

        while (p != NULL)
        {
            os << " " << p->data;
            p = p->next;
        }
        os << " >";
        // print remaining elements in list

        return os;
    }
};


int main()
{
    std::cout << std::endl;

    dll_t L;            std::cout << " 1" << L << std::endl;
    L.insert("GTR");    std::cout << " 2" << L << std::endl;
    L.insert("ATL");    std::cout << " 3" << L << std::endl;
    L.next();           std::cout << " 4" << L << std::endl;
    L.insert("CPH");    std::cout << " 5" << L << std::endl;
    L.insert("SLC");    std::cout << " 6" << L << std::endl;
    L.next();           std::cout << " 7" << L << std::endl;
    L.next();           std::cout << " 8" << L << std::endl;
    L.next();           std::cout << " 9" << L << std::endl;
    L.next();           std::cout << "10" << L << std::endl;
    L.prev();           std::cout << "11" << L << std::endl;
    L.prev();           std::cout << "12" << L << std::endl;
    L.prev();           std::cout << "13" << L << std::endl;
    L.prev();           std::cout << "14" << L << std::endl;
    L.next();           std::cout << "15" << L << std::endl;
    L.next();           std::cout << "16" << L << std::endl;
    L.remove();         std::cout << "17" << L << std::endl;
    L.remove();         std::cout << "18" << L << std::endl;
    L.remove();         std::cout << "19" << L << std::endl;

    std::cout << std::endl;
}