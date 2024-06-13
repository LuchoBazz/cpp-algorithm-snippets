
template <typename Container>
auto get_min(Container &c) -> typename Container::value_type {
    assert(!c.empty());
    return *c.begin();
}

template <typename Container>
auto get_max(Container &c) -> typename Container::value_type {
    assert(!c.empty());
    return *c.rbegin();
}

template <typename Container>
auto erase_min(Container &c) -> typename Container::value_type {
    assert(!c.empty());
    auto to_return = get_min(c);
    c.erase(c.begin());
    return to_return;
}

template <typename Container>
auto erase_max(Container &c) -> typename Container::value_type {
    assert(!c.empty());
    auto to_return = get_max(c);
    c.erase(--c.end());
    return to_return;
}
