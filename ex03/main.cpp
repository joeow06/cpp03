/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:00:37 by jow               #+#    #+#             */
/*   Updated: 2025/10/22 00:52:01 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void print_status(DiamondTrap &a)
{
	std::cout << a.getName() << " | Hit Point: " << a.getHitPt() 
		<< " | Energy Point: " << a.getEnergyPt() << " | Attack Damage: " 
		<< a.getAtkDmg() << std::endl;
}

int main(void)
{	
	std::cout << "---------- DiamondTrap Tests ----------\n" << std::endl;
	DiamondTrap a("apple");
	print_status(a);
	DiamondTrap b("banana");
	print_status(b);
	std::cout <<std::endl;

	std::cout << "---------- guardGate() test ----------" << std::endl;
	a.guardGate();
	b.guardGate();
	std::cout <<std::endl;

	std::cout << "---------- highFivesGuys() test ----------" << std::endl;
	a.highFivesGuys();
	b.highFivesGuys();
	std::cout <<std::endl;
	
	std::cout << "---------- whoAmI() test ----------" << std::endl;
	a.whoAmI();
	b.whoAmI();
	std::cout <<std::endl;

	std::cout << "---------- Attack() ----------" << std::endl;
	a.attack(b.getName());
	b.takeDamage(30);
	print_status(b);
	std::cout <<std::endl;

	std::cout << "---------- Copy Constructor ----------" << std::endl;
	DiamondTrap c(a);
	print_status(c);
	c.takeDamage(10000);
	print_status(c);
	std::cout <<std::endl;

	std::cout << "---------- Copy Assignment Operator ----------" << std::endl;
	DiamondTrap d;
	d = a;
	print_status(d);
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
	ClapTrap *heapDiamond = new DiamondTrap("HeapScav");
	heapDiamond->attack("random guy");
	delete heapDiamond;
	std::cout <<std::endl;
}
