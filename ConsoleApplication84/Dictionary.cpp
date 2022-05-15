#include "Dictionary.h"

template<class T>
void Dictionary<T>::MAKENULL()
{
    int i;
    for (i = 0; i < size_dict; i++)
        dict[i] = nullptr;
}

template<class T>
bool Dictionary<T>::MEMBER(T x)
{
    Node* current = nullptr;
    current = dict[h(x)];
    while (current != nullptr)
    {
        if (strcmp(typeid(x).name(), "char *") == 0)
            if (strcmp(current->element, x) == 0)
                return true;
            else
                if (current->element == x)
                    return true;
        if (current->next == nullptr)
            return false;
        current = current->next;
    }
    return false;
}

template<class T>
void Dictionary<T>::INSERT(T x)
{
    int bucket;
    Node* oldheader;

    if (!MEMBER(x))
    {
        bucket = h(x);
        oldheader = dict[bucket];
        dict[bucket] = new Node;
        strcpy_s(dict[bucket]->element, x);
        dict[bucket]->next = oldheader;
    }
}

template<class T>
void Dictionary<T>::DELETE(T x)
{
    int bucket;
    Node* oldheader;

    bucket = h(x);
    if (strcmp(typeid(x).name(), "char *") == 0)
        if (dict[bucket] != nullptr)
        {
            if (!MEMBER(x))
                return;
            if (strcmp(dict[bucket]->element, x) == 0)
                dict[bucket] = dict[bucket]->next;
            else
            {
                oldheader = dict[bucket];
                while (oldheader->next != nullptr)
                {
                    if (strcmp(oldheader->next->element, x) == 0)
                    {
                        oldheader->next = oldheader->next->next;
                        return;
                    }
                    else
                        oldheader = oldheader->next;
                }
            }
        }
        else
            if (dict[bucket] != nullptr)
            {
                if (!MEMBER(x))
                    return;
                if (dict[bucket]->element == x)
                    dict[bucket] = dict[bucket]->next;
                else
                {
                    oldheader = dict[bucket];
                    while (oldheader->next != nullptr)
                    {
                        if (oldheader->next->element == x)
                        {
                            oldheader->next = oldheader->next->next;
                            return;
                        }
                        else
                            oldheader = oldheader->next;
                    }
                }
            }

}

template<class T>
void Dictionary<T>::PRINT() {
    Node* current;
    for (int i = 0; i < size_dict; i++) {
        printf("\n[%d]", i);
        current = dict[i];
        while (current != nullptr) {
            printf("%s", current->element);
            if (current->next != nullptr)
                printf(", ");
            current = current->next;
        }
    }
    printf("\n");
}

template<class T>
int Dictionary<T>::h(T x) {
    int sum = 0;
    if (strcmp(typeid(x).name(), "char *") == 0)
        for (unsigned int i = 0; i < strlen(x); i++)
            sum += (int)x[i];
    else
        sum += (int)x;
    return sum % (size_dict);
}