/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    void printInterval(vector<Interval> intervals){
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
        }
        cout<<"##########################"<<endl;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()<=1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end(),[] (Interval const& a, Interval const& b) {return a.start < b.start;});
        int i=0;
        std::vector<Interval>::iterator it;
        while(i<intervals.size()-1){
             if(intervals[i].start<=intervals[i+1].start && intervals[i+1].start<=intervals[i].end){
                struct Interval interv(0,0);
                interv.start=intervals[i].start;
                if(intervals[i+1].end>=intervals[i].end){
                    interv.end=intervals[i+1].end;
                }else{
                    interv.end=intervals[i].end;
                }
                intervals.erase(intervals.begin()+i,intervals.begin()+i+2);
                intervals.insert(intervals.begin()+i,interv);
             }else{
                 i++;
             }
        }
        return intervals;
    }
};