/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 03:25:01 by jow               #+#    #+#             */
/*   Updated: 2025/10/22 00:23:59 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap copy assignment operator called" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	hitPt = 100;
	energyPt = 100;
	atkDmg = 30;
	std::cout << "FragTrap " << name << " is created" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->getName() << " requests high-fives!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->getHitPt() == 0)
	{
		std::cout << "FragTrap " << this->getName() << " is already dead." << std::endl;
		return;
	}
	if (this->getEnergyPt() == 0)
	{
		std::cout << "FragTrap " << this->getName() << " has no energy points left to attack."
				  << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->getName() << " attacks " << target
			  << ", causing " << this->getAtkDmg() << " points of damage!"
			  << std::endl;
	deductEnergy();
}