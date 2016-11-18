#include "parts.h"

void createkategori(listkategori *L)
{
    first(*L)=Nil;
    last(*L)=Nil;
}

void createmerek(listmerek *L)
{
    first(*L)=Nil;
    last(*L)=Nil;
}

void createbarang(listbarang *L)
{
    first(*L)=Nil;
    last(*L)=Nil;
}

address_kategori alokasikategori(infotypekategori X){
    address_kategori P;
    P = (address_kategori)malloc(sizeof(elm_list_kategori));
    strcpy(info(P),X);
    //info(P)=X;
    next(P)=Nil;
    prev(P)=Nil;
    first(Lmerek(P))=Nil;
    last(Lmerek(P))=Nil;
    return P;
}
address_merek alokasimerek(infotypemerek X){
    address_merek P;
    P = (address_merek)malloc(sizeof(elm_list_merek));
    strcpy(info(P),X);
    //info(P)=X;
    next(P)=Nil;
    prev(P)=Nil;
    first(Lbarang(P))=Nil;
    last(Lbarang(P))=Nil;
    return P;
}
address_barang alokasibarang(infotypebarang X){
    address_barang P;
    P = (address_barang)malloc(sizeof(elm_list_barang));
    strcpy(info(P).kode,X.kode);
    strcpy(info(P).nama,X.nama);
    info(P).harga=X.harga;
    info(P).jumlah=X.jumlah;
    info(P).totalharga=info(P).jumlah*info(P).harga;
    next(P)=Nil;
    prev(P)=Nil;
    return P;
}

address_kategori findElmKategori(listkategori L, char kat[20]){
    address_kategori P = first(L);
    address_kategori temp=Nil;
    while(P!=Nil)
    {
        if (strcmp(info(P),kat)==0)
        {
            temp=P;
            break;
        }
        P=next(P);
    }
    return temp;
}
address_merek findElmmerek(listmerek L, char mer[20]){
    address_merek P = first(L);
    address_merek temp = Nil;
    while(P!=Nil)
    {
        if (strcmp(info(P),mer)==0)
        {
            temp=P;
            break;
        }
        P=next(P);
    }
    return temp;
}
address_barang findElmkodebarang(listbarang L, char kode[5]){
    address_barang P = first(L);
    address_barang temp = Nil;
    while(P!=Nil)
    {
        if (strcmp(info(P).kode,kode)==0)
        {
            temp = P;
            break;
        }
        P=next(P);
    }
    return temp;
}

address_kategori findElmKategori1(listkategori L, char kat[20]){
    address_kategori P = first(L);
    while(P!=Nil)
    {
        if (strcmp(info(P),kat)==0)
        {
            cout << "Kategori Ditemukan"<<endl;
            break;
        }
        P=next(P);
    }
    return P;
}

address_merek findElmmerek1(listmerek L, char mer[20]){
    address_merek P = first(L);
    while(P!=Nil)
    {
        if (strcmp(info(P),mer)==0)
        {
            cout << "Merek Ditemukan"<<endl;
            break;
        }
        P=next(P);
    }
    return P;
}



address_barang findElmkodebarang1(listbarang L, char kode[5]){
    address_barang P = first(L);
    while(P!=Nil)
    {
        if (strcmp(info(P).kode,kode)==0)
        {
            system("cls");
            cout << "Kategori Ditemukan"<<endl;
            while (P!=Nil)
            {
            cout <<"Data yang ditemukan adalah"<<endl;
            cout << "------------------------------"<<endl;
            cout<<"  Kode barang    : "<<info(P).kode<<endl;
            cout<<"  Nama barang    : "<<info(P).nama<<endl;
            cout<<"  Harga barang   : Rp."<<info(P).harga<<",-"<<endl;
            cout<<"  Jumlah barang  : "<<info(P).jumlah<<endl;
            cout<<"  Total Harga    : Rp."<<info(P).totalharga<<",-"<<endl;
            cout<<endl;
            P=next(P);
            }
            break;
        }
        P=next(P);
    }
    return P;
}
void insertFirstkategori(listkategori *L, infotypekategori X){
    address_kategori P=alokasikategori(X);
    if (first(*L)==Nil && last(*L)==Nil)
    {
        first(*L)=P;
        last(*L)=P;
        next(P)=Nil;
        prev(P)=Nil;
    }
    else
    {
        next(P)=first(*L);
        prev(first(*L))=P;
        first(*L)=P;
    }
}

void insertFirstmerek(listkategori *L,char kat[20], address_merek Pm){
    //address_merek Pm = alokasimerek(X);
    address_kategori P = findElmKategori(*L, kat);
    if (first(Lmerek(P))==Nil && last(Lmerek(P))==Nil)
    {
        first(Lmerek(P))=Pm;
        last(Lmerek(P))=Pm;
        next(Pm)=Nil;
        prev(Pm)=Nil;
        cout<<"insert berhasil\n";
    }
    else
    {
        next(Pm)=first(Lmerek(P));
        prev(first(Lmerek(P)))=Pm;
        first(Lmerek(P))=Pm;
        cout<<"insert berhasil\n";
    }
}

void insertFirstbarang(listkategori *L, char kat[20], char mer[20], address_barang Pb){
    address_kategori Pk = findElmKategori(*L, kat);
    listmerek Q = Lmerek(Pk);
    address_merek P = findElmmerek(Q, mer);
    if (first(Lbarang(P))==Nil && last(Lbarang(P))==Nil)
    {
        first(Lbarang(P))=Pb;
        last(Lbarang(P))=Pb;
        next(Pb)=Nil;
        prev(Pb)=Nil;
        cout<<"insert berhasil\n";
    }
    else
    {
        next(Pb)=first(Lbarang(P));
        prev(first(Lbarang(P)))=Pb;
        first(Lbarang(P))=Pb;
        cout<<"insert berhasil\n";
    }
}
void delFirstkategori(listkategori *L, address_kategori *P){
    (*P)=first(*L);
    first(*L)=next(first(*L));
    prev(first(*L))=Nil;
    next(*P)=Nil;
    free(P);
}
void delLastKategori(listkategori *L, address_kategori *P){
    if(first(*L) == Nil){
        cout<<"Empety"<<endl;
    }else{
        address_kategori last = first(*L);
        address_kategori prev;
        while (next(last) != Nil){
            prev = last;
			last = next(last);
		}
		next(prev)=Nil;
		free(P);
    }
}
void delSearchkategori(listkategori *L, char kat[20]){
    address_kategori P = findElmKategori(*L, kat);
    if (P==first(*L)){
        first(*L) = Nil;
        last(*L) = Nil;
        free(P);
    }else{if(P==last(*L)){
        address_kategori Q = prev(P);
        next(Q) = Nil;
        prev(P) = Nil;
        last(*L) = Q;
        free(P);
        }else{
        address_kategori Q = prev(P);
        next(Q) = next(P);
        prev(next(P)) = Q;
        next(P) = Nil;
        prev(P) = Nil;
        free(P);
        }
    }
}

void delSearchMerek(listkategori *L,char kat[20], char mer[20]){
    address_kategori Pk = findElmKategori(*L, kat);
    listmerek Q = Lmerek(Pk);
    address_merek P = findElmmerek(Q, mer);
    if (P==first(Q)){
        first(Q) = Nil;
        last(Q) = Nil;
        free(P);
    }
//    else{if(P==last(Q)){
//        address_merek R = prev(P);
//        next(R) = Nil;
//        prev(P) = Nil;
//        last(Q) = R;
//        free(P);
//    }
    else{
        address_merek R = prev(P);
        next(R) = next(P);
        prev(next(P)) = R;
        next(P) = Nil;
        prev(P) = Nil;
        free(P);
        }
    }
//}

void delSearchBarang(listkategori *L,char kat[20], char mer[20], char co[5]){
    address_kategori Pk = findElmKategori(*L, kat);
    listmerek Lm = Lmerek(Pk);
    address_merek Pm = findElmmerek(Lm, mer);
    listbarang Q = Lbarang(Pm);
    address_barang P = findElmkodebarang(Q, co);
    if (P==first(Q)){
        first(Q) = Nil;
        last(Q) = Nil;
        free(P);
    }else{if(P==last(Q)){
        address_barang R = prev(P);
        next(R) = Nil;
        prev(P) = Nil;
        last(Q) = R;
        free(P);
        }else{
        address_barang R = prev(P);
        next(R) = next(P);
        prev(next(P)) = R;
        next(P) = Nil;
        prev(P) = Nil;
        free(P);
        }
    }
}

void renamekategori(listkategori L,char lama[20], char N[20]){
    address_kategori P;
    P = findElmKategori(L, lama);
    while (P!=Nil){
        if(strcmp(info(P),N)){
            strcpy(info(P),N);
            break;
        }
        P = next(P);
    }
}
void renamemerek(listkategori L, char kat[20], char mer[20] , char N[20]){
    address_kategori P = findElmKategori(L, kat);
    listmerek Q = Lmerek(P);
    address_merek R;
    R = findElmmerek(Q, mer);
    while (R!=Nil){
        if( strcmp(info(R),N)){
            strcpy(info(R),N);
            break;
        }
        R = next(R);
    }
}

void renamekodebarang(listkategori L, char kat[20], char mer[20], char kode[5], char N[20]){
    address_kategori P = findElmKategori(L, kat);
    listmerek Q = Lmerek(P);
    address_merek M = findElmmerek(Q,mer);
    listbarang B = Lbarang(M);
    address_barang R = findElmkodebarang(B, kode);
    while (R!=Nil){
        if( strcmp(info(R).kode,N)){
            strcpy(info(R).kode,N);
            break;
        }
        R = next(R);
    }
}


void viewkategori(listkategori L){
    address_kategori P;
    P = first(L);
    system("cls");
    cout << "Daftar Kategori"<<endl;
    cout << "=================="<<endl;
    if(P!=Nil){
    while (P!=Nil)
    {
        cout << "Kategori : "<<info(P);
        cout <<endl;
        P = next(P);
    }
    }else {
        cout << "Kategori Kosong"<<endl;
    }
}
void viewmerek(listkategori L){
    address_kategori P;
    char kat[20];
    cout << "Cari kategori : ";
    cin >> kat;
    P = findElmKategori(L, kat);
    listmerek Q;
    Q = Lmerek(P);
    address_merek M = first(Q);
    system("cls");
    cout << "Daftar Merek"<<endl;
    cout << "=================="<<endl;
    if(M!=Nil){
    while (M!=Nil)
    {
        cout << "Merek : "<<info(M);
        cout <<endl;
        M = next(M);
    }
    }else {
        cout << "Data Merek kosong"<<endl;
    }
}
void viewbarang(listkategori L){
    address_kategori P;
    listmerek Q;
    listbarang B;
    char kat[20], mer[20];
    cout << "Cari kategori : ";
    cin >> kat;
    P = findElmKategori(L, kat);
    Q = Lmerek(P);
    cout << "Cari merek : ";
    cin >> mer;
    address_merek M = findElmmerek(Q, mer);
    B = Lbarang(M);
    address_barang R = first(B);
    system("cls");
    cout << "Daftar Barang"<<endl;
    cout << "=================="<<endl;
    while (R!=Nil)
        {
            cout<<"  Kode barang    : "<<info(R).kode<<endl;
            cout<<"  Nama barang    : "<<info(R).nama<<endl;
            cout<<"  Harga barang   : Rp."<<info(R).harga<<",-"<<endl;
            cout<<"  Jumlah barang  : "<<info(R).jumlah<<endl;
            cout<<"  Total Harga    : Rp."<<info(R).totalharga<<",-"<<endl;
            cout<<endl;
            R=next(R);
        }
}

void viewall(listkategori L){
    address_kategori P;
    listmerek Q;
    listbarang B;
    P = first(L);
    cout << "Daftar Gudang"<<endl;
    cout << "=================="<<endl;
    while (P!=Nil){
    cout << "Kategori : "<<info(P)<<endl;
    cout << "-------------------"<<endl;
    Q = Lmerek(P);
    address_merek M = first(Q);
    if(M!=Nil){
    while (M!=Nil)
        {
            cout<<endl;
            cout<<" Nama merek     : "<<info(M)<<endl;
            cout << "============================"<<endl;
            B = Lbarang(M);
            address_barang R = first(B);
            while (R!=Nil)
            {
                cout<<"  Kode barang    : "<<info(R).kode<<endl;
                cout<<"  Nama barang    : "<<info(R).nama<<endl;
                cout<<"  Harga barang   : Rp."<<info(R).harga<<",-"<<endl;
                cout<<"  Jumlah barang  : "<<info(R).jumlah<<endl;
                cout<<"  Total Harga    : Rp."<<info(R).totalharga<<",-"<<endl;
                cout<<endl;
                R=next(R);
            }
            M=next(M);
        }
    }else {
        cout << " Merek Kosong"<<endl;
    }
    P=next(P);
    }
}
