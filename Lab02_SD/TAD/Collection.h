#ifndef LAB02_SD_COLLECTION_H
#define LAB02_SD_COLLECTION_H

typedef int TElem;

struct Pereche {
    TElem elem;
    int frecv;
};
class Collection {
private:
    Pereche* elems;
    int len;
    int capacity;
    void resize();
public:
    Collection();
    Collection(const Collection& other);
    Collection& operator=(const Collection& other);
    void add(TElem elem);
    bool remove(TElem elem);
    bool search(TElem elem);
    int noOccurrences(TElem elem);
    int size();
    TElem getAt(int position);
    ~Collection();
};


#endif //LAB02_SD_COLLECTION_H