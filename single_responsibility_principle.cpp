

struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string &title): title(title) {}

    void add_entry(const string& entry)
    {
        static int count = 1;
        entries.push_back(lexical_cast<string>(count++) + ": " + entry);
    }

    // wrong way to do this
    // void save(const string& filename){
    //     ofstream ofs(filename);
    //     for(auto& e: entries){
    //         ofs << e << endl;
    //     }
    // }

};

//The problem is that with the above example, for instance the persistence functionality needs to be modified for each class(for ex Journal, Machine, etc)
struct PersistenceManager
{
    static void save(const Journal& j, const string& filename){
         ofstream ofs(filename);
         for(auto& e: entries){
          ofs << e << endl;
         }
    }

};


int main(){

    Journal journal{"Dear Diary"};
    jounral.add_entry("I ate a bug");
    journal.add_entry("I cried today");

    //journal.save("diary.txt");

    PersistenceManager pm;
    pm.save(jounral, "diary.txt");



    return 0;
}


