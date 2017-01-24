#pragma once
class Target
{
public:
    Target();
    Target(size_t price, std::string type, std::string name);
    Target(const Target &);
    ~Target();

    bool operator<(const Target &);
    bool operator==(const Target &);

    size_t price;
    std::string type;
    std::string name;
};

