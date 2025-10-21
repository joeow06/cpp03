/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 03:25:01 by jow               #+#    #+#             */
/*   Updated: 2025/10/21 04:01:33 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "ScavTrap copy assignment operator called" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->setAtkDmg(100);
	this->setEnergyPoint(50);
	this->setAtkDmg(20);
	std::cout << "ScavTrap " << this->getName() << " is created" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getHitPt() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is already dead." << std::endl;
		return ;
	}
	if (this->getEnergyPt() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no energy points left to attack." 
			<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target 
		<< ", causing " << this->getAtkDmg() << " points of damage!" 
		<< std::endl;
	deductEnergy();
}