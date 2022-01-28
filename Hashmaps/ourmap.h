//hashmap implementation

//string -> value v
#include <string>
using namespace std;
template<typename v>
class MapNode
{
    string key;
    v value;
    MapNode *next;
    MapNode(string key, v value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};
template <typename v>
class ourmap
{
    MapNode<v> **buckets;
    int size;
    int numBuckets;

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<v> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        ~ourmap()
        {
            for (int i = 0; i < numBuckets; i++)
            {
                delete buckets[i];
            }
            delete[] buckets;
        }

        int size()
        {
            return count;
        }
        v getValue(string key)
        {
            int bucketIndex=getBucketIndex(key);
            MapNode<v> *head=buckets[bucketIndex];
            while(head!=NULL){
                if(head->key = key){
                    return head->value;
                }
                head=head->next;
            }
            return 0;
        }

    private:
       double getLoadFactor(){
           return (1.0*count)/numBuckets;
       }
        int getBucketIndex(key)
        {
            int hashCode = 0;
            int currentCoeff = 1;
            for (int i = key.length() - 1; i >= 0; i--)
            {
                hashCode += key[i] * currentCoeff;
                hasCode = hashCode % numBuckets;
                currentCoeff *= 37;
                currentCoeff = currentCoeff % numBuckets;
            }
            return hashCode % numBuckets;
        }

        void rehash(){
            MapNode<v> **temp = buckets;
            buckets = new MapNode<v>[2*numBuckets];
            for(int i=0;i<2*numBuckets;i++){
                buckets[i]=NULL;
            }
            int oldBucketCount = numBuckets;
            numBuckets *=2;
            count =0;
            for(int i=0;i<oldBucketCount;i++){
                MapNode<v> *head=temp[i];
                while(head!=NULL){
                    string key =head->key;
                    v value = head->value;
                    insert(key,value);
                    head=head->next;
                }
            }
            for(int i=0;i<oldBucketCount;i++){
                MapNode<v>*head = temp[i];
                delete head;
            }
            delete [] temp;
        }
        void insert(string key, v value)
        {
            int bucketIndex = getBucketIndex(key);
            MapNode<v> *head = buckets[bucketIndex];
            while (head != NULL)
            {
                if (head->key == key)
                {
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            head = buckets[bucketIndex];
            MapNode<v> *node = new MapNode<v>(key, value);
            node->next = head;
            buckets[bucketIndex] = node;
            count++;
            //rehashing
            double loadFactor = (1.0*count)/numBuckets;
            if(loadFactor > 0.7){
                rehash();
            }
        }

        v remove(string key)
        {
            int bucketIndex = getBucketIndex( key);
            MapNode<v> *head = buckets[bucketIndex];
            MapNode<v> *prev = NULL;
            while (head != NULL)
            {
                if (head->key == key)
                {
                    if (prev == NULL)
                    {
                        backets[bucketIndex] = head->next;
                    }
                    else
                    {
                        prev->next = head->next;
                    }
                    v value = head->value;
                    head->next = NULL;
                    delete head;
                    count--;
                    return value;
                }
                prev = head;
                head = head->next;
            }
            return 0;
        }
    }
};