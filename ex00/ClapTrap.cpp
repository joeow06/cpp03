/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:11:51 by jow               #+#    #+#             */
/*   Updated: 2025/10/21 00:53:02 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hitPt(defHitPt), energyPt(defEnerPt), atkDmg(defAtkDmg)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {std::cout << "ClapTrap destroyed" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPt = other.hitPt;
		this->energyPt = other.energyPt;
		this->atkDmg = other.atkDmg;
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string _name) : name(_name), hitPt(defHitPt), 
	energyPt(defEnerPt), atkDmg(defAtkDmg)
{
	std::cout << "ClapTrap " << name << " is created" << std::endl;
}

std::string ClapTrap::getName(void) {return (name);}
unsigned int ClapTrap::getHitPt(void) {return (hitPt);}
unsigned int ClapTrap::getEnergyPt(void) {return (energyPt);}
unsigned int ClapTrap::getAtkDmg(void) {return (atkDmg);}

void ClapTrap::attack(const std::string& target)
{
	if (this->getHitPt() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is already dead." << std::endl;
		return ;
	}
	if (this->getEnergyPt() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has no energy points left to attack." 
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target 
		<< ", causing " << this->getAtkDmg() << " points of damage!" 
		<< std::endl;
	//takeDamage(atkDmg);
	deductEnergy();
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPt() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is already dead." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " receives " << amount << 
		" amount of damage!" << std::endl;
	hitPt -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPt() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is already dead." << std::endl;
		return ;
	}
	if (this->getEnergyPt() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has no energy points left to repair itself." 
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " repairs itself by " 
	<< amount << " points!" << std::endl;
	hitPt += amount;
	deductEnergy();
}

void ClapTrap::deductEnergy(void) { energyPt -= 1;}
