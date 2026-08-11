// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        finalSort(pairs,0,pairs.size()-1);
        return pairs;
    }

    int partition(vector<Pair>& pairs, int s, int e){
       auto pivot = pairs.at(e).key;
       int i = s-1;
       for (int j = s; j < e; j++) {
        if(pairs.at(j).key<pivot){
            i++;
            swap(pairs.at(i),pairs.at(j));
        }
       }
       swap(pairs.at(i+1),pairs.at(e));
       return i+1;
    }

    void finalSort(vector<Pair>& pairs, int s, int e){
        if(s<e){
            int pi = partition(pairs,s,e);
            finalSort(pairs,s,pi-1);
            finalSort(pairs,pi+1,e);
        }
    }
};
