#ifndef NODOBST_H
#define NODOBST_H

template <class T>
class NodoBST {
public:
    NodoBST();
    NodoBST(T);

    void setDato(T);
    T getDato();

    void setIzq(NodoBST<T>*);
    NodoBST<T>* getIzq();

    void setDer(NodoBST<T>*);
    NodoBST<T>* getDer();

    int compareTo(T);

private:
    T dato;
    NodoBST<T>* izq;
    NodoBST<T>* der;
};

#endif // NODOBST_H
