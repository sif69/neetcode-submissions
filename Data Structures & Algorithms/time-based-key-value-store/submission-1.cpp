class TimeMap {
public:
    unordered_map<string, map<int, string>> m;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }

   string get(string key, int timestamp) {
    auto& mp = m[key];
    auto it = mp.lower_bound(timestamp);

    // Case 1: exact match
    if (it != mp.end() && it->first == timestamp)
        return it->second;

    // Case 2: no exact match → step back
    if (it == mp.begin()) return "";  // nothing before this
    return prev(it)->second;
}
};