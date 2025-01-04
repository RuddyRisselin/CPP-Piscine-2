#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

class Bureaucrat
{
private:
    const std::string _name;
	int _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string _name, int _grade);
	Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif	BUREAUCRAT_H