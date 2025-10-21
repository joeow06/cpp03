/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:00:37 by jow               #+#    #+#             */
/*   Updated: 2025/10/21 21:29:40 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void print_status(ScavTrap &a)
{
	std::cout << a.getName() << " | Hit Point: " << a.getHitPt() 
		<< " | Energy Point: " << a.getEnergyPt() << " | Attack Damage: " 
		<< a.getAtkDmg() << std::endl;
}

int main(void)
{
	std::cout << "---------- ScavTrap Tests ----------\n" << std::endl;
	ScavTrap a("apple");
	print_status(a);
	ScavTrap b("banana");
	print_status(b);
	std::cout <<std::endl;
	
	std::cout << "---------- Guard Gate ----------" << std::endl;
	a.guardGate();
	b.guardGate();
	std::cout <<std::endl;

	std::cout << "---------- Attack() ----------" << std::endl;
	a.attack(b.getName());
	b.takeDamage(20);
	print_status(b);
	std::cout <<std::endl;

	std::cout << "---------- Copy Constructor ----------" << std::endl;
	ScavTrap c(a);
	print_status(c);
	c.takeDamage(10000);
	print_status(c);
	std::cout <<std::endl;

	std::cout << "---------- Take damage after death test(shouldnt work) ----------" << std::endl;
	std::cout << c.getName() << " tries to take damage" <<std::endl;
	c.takeDamage(1);
	print_status(c);
	std::cout <<std::endl;

	std::cout << "---------- Tries to attack after death test(shouldnt work) ----------" << std::endl;
	std::cout << c.getName() << " tries to attack!" <<std::endl;
	c.attack("dummy");
	print_status(c);
	std::cout <<std::endl;

	std::cout << "---------- Tries to repair itself after death test(shouldnt work) ----------" << std::endl;
	std::cout << c.getName() << " tries repair itself!" <<std::endl;
	c.beRepaired(1000000);
	print_status(c);
	std::cout <<std::endl;

	std::cout << "---------- Energy depletion test ----------" << std::endl;
	print_status(b);
	std::cout << b.getName() << " uses all its energy!" <<std::endl;
	for (unsigned int i = 0; i < 50; i++)
		b.attack("dummy");
	print_status(b);
	std::cout << b.getName() << " tries to do all sorts of stuff after it has no energy..." <<std::endl;
	b.attack("dummy");
	b.takeDamage(10);
	b.beRepaired(100);
	print_status(b);
	std::cout <<std::endl;
	
	std::cout << "---------- Virtual Destructor test ----------" << std::endl;
	ClapTrap *heapScav = new ScavTrap("HeapScav");
	heapScav->attack("random guy");
	delete heapScav;
	std::cout <<std::endl;
	
}

/*
Without virtual destructor:
When we have BaseClass pointers to DerivedClass 
objects instances, if we try to delete DerivedClass
objects using BaseClass pointers, only BaseClass
destructor is going it run.

Making BaseClass destructor virtual guarantees that 
the DerivedClass object is destructed properly

Also as a guideline, if we have a virtual function
in a class, we should also add a virtual destructor
to ensure against any surprises later on
*/