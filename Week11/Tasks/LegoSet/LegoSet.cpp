#include "LegoSet.h"

int LegoSet::idCounter = 1;

std::strong_ordering LegoSet::operator<=>(const LegoSet& other) const
{
    return this->getPieceCount() <=> other.getPieceCount();
}

std::string enumToString(const Theme& t)
{
    switch (t) {
    case Theme::Lego_Star_Wars: return "Lego Star Wars";
    case Theme::Lego_Ninjago: return "Lego Ninjago";
    default: return "Unkown Theme";
    }
}


LegoSet::LegoSet(const std::string& name, int pieceCount, const Theme& t) : id(idCounter++), name(name), pieceCount(pieceCount), theme(t)
{
}

//const std::string& LegoSet::enumToString(const Theme& t)
//{
//    switch (t) {
//    case Theme::Lego_Star_Wars: return "Lego Star Wars";
//        break;
//    case Theme::Lego_Ninjago: return "Lego Ninjago";
//        break;
//    }
//    return " ";
//}

bool LegoSet::operator==(const LegoSet& other) const
{
    //std::string first = enumToString(this->theme);
    //std::string second = enumToString(other.theme);
    //if (this->pieceCount == other.pieceCount && first == second)
    //{
    //    return true;
    //}
    //return false;
    return this->pieceCount == other.pieceCount;
}

int LegoSet::getPieceCount() const
{
    return pieceCount;
}

const Theme& LegoSet::getTheme() const
{
    return theme;
}

const std::string& LegoSet::getName() const
{
    return name;
}


std::ostream& operator<<(std::ostream& os, const LegoSet& set)
{
    os << "| Lego Set's name: " << set.name
        << "| id: " << set.id
        << "| piece count: " << set.pieceCount
        << "| theme: " << enumToString(set.theme) << std::endl;
    return os;
}
