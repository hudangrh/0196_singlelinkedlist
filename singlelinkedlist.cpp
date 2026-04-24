#include <iostream>
using namespace std;

class node
{
public:
    int noMhs;
    node *next;
};

class Linkedlist
{
    node *START;

public:
    Linkedlist()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        node *nodeBaru = new node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak di ijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        node *previous = START;
        node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak di ijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool search(int nim, node **previous, node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current !=NULL);
    }

    bool delNode(int nim)
    {
        node *current, *previous;
        if (!search(nim, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nlist kosong\n";
        }
        else
        {
            cout << "\nData di dalam list adalah:\n";
            node *currentnode = START;
            while (currentnode != NULL)
            {
                cout << currentnode->noMhs << endl;
                currentnode = currentnode->next;
            }
            cout << endl;
        }
    }
}

int main()
{
    Linkedlist mhs;
    int nim;
    char ch;
    do
    {
        cout << endl
            << "menu";
        cout << endl
            << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Menampilkan semua data di dalam list secara terbalik" << endl;
        cout << "5. Mencari data dalam list" << endl;
        cout << "6. Keluar" << endl;
        cout << endl
             << "masukkan pilihan (1-5): ";
             cin >> ch;
             switch (ch)
             {
                case '1':
             {
                mhs.addNode();
             }
            break;

            case '2':
            {
                if(mhs.listEmpty())
                {
                    cout << endl;
                    cout << "List kosong" << endl;
                    break;
                }
                cout << endl
                     << "\nMasukkan no mahasiswa yang akan di hapus : "\
                cin >> nim;
                if (mhs.delNode)(nim) == false)
                    cout << endl
                         << "Data tidak di temukan" << endl;
                else    
                    cout << "\nData dengan nomor mahasiswa " << nim << " berhasil dihapus\n"
            }
            break;

                case '3':
                {
                    mhs.traverse();
                }
                break;

                case '4':
                {
                     if (mhs.listEmpty() == true)
                     {
                        cout << "\nList kosong\n;
                        break;"
                     }
                     node *previous, *current;
                     cout << "\nMasukkan no mahasiswa yang di cari : ";
                     cin >> nim;
                     if (mhs.search(nim, *previous, *current) == false)
                        cout << "\nData tidak di temukan\n";
                    else
                    {
                        cout << "\nData di temukan\n";
                        cout << "NIM mahasiswa : " << current-> noMhs << endl;
                    }
                    break;
                }

                case '5';
                    break;

                default:
                cout << "\nPilihan salah!\n";
            }    
        }   while (ch != '5');
        
        return 0;
    }
