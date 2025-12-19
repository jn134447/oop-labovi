
#ifndef GNOME_H
#define GNOME_H

class Gnome : public Enemy
{
protected:
    int attackDamage = 5;

public:
    Gnome(std::string name);

    void attackPlayer(Player &player) override;
    void specialAbility() override;
};

#endif