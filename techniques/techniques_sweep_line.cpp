struct Event {
    int time;
    int delta;
    int idx;

    bool operator<(const Event &other) const { return time < other.time; }
};

// Usage:
// vector<Event> events;
// events.reserve(2*n);
// int from, to;
// for(int i = 0; i < n; ++i) {
//     read from and to values
//     events.push_back(Event{from, 1, i});
//     events.push_back(Event{to, -1, i});
// }
// sort(events.begin(), events.end());
// for(const auto &event: events) {
//     process_logic(event.delta); for example
//     total += event.delta;
//     best = max(best, total);
// }
