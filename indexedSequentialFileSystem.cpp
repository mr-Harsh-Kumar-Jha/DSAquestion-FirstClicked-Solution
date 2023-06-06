#include<bits/stdc++.h>
using namespace std;

struct Record {
    int key;
    string data;
};

int main() {
    fstream file("data.dat", ios::out | ios::binary);
    ofstream indexFile("index.dat", ios::out | ios::binary);

    if (!file || !indexFile) {
        cout << "Failed to create the file(s)." << endl;
        return 1;
    }

    Record records[] = {
        {100, "Data 1"},
        {50, "Data 2"},
        {75, "Data 3"},
        {200, "Data 4"}
    };

    unordered_map<int, streampos> index;

    for (const Record& record : records) {
        index[record.key] = file.tellp();
        file.write((char*)(&record), sizeof(Record));
    }

    for (const auto& entry : index) {
        indexFile.write((char*)(&entry), sizeof(pair<int, streampos>));
    }

    file.close();
    indexFile.close();

    // Perform a search using the index
    int searchKey = 75;
    ifstream indexReadFile("index.dat", ios::in | ios::binary);

    if (!indexReadFile) {
        cout << "Failed to open the index file for reading." << std::endl;
        return 1;
    }

   pair<int, streampos> indexEntry;
   bool found = false;

    while (indexReadFile.read((char*)(&indexEntry), sizeof(pair<int, streampos>))) {
        if (indexEntry.first == searchKey) {
            found = true;
            break;
        }
    }

   indexReadFile.close();

   if (found) {
      ifstream dataReadFile("data.dat", ios::in | ios::binary);

      if (!dataReadFile) {
         cout << "Failed to open the data file for reading." << std::endl;
         return 1;
      }

        Record foundRecord;
        dataReadFile.seekg(indexEntry.second);
        dataReadFile.read((char*)(&foundRecord), sizeof(Record));
        cout << "Record found: Key = " << foundRecord.key << ", Data = " << foundRecord.data << endl;

        dataReadFile.close();
    } else {
        cout << "Record not found." << endl;
    }

    return 0;
}
