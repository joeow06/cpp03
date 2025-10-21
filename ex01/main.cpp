/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:00:37 by jow               #+#    #+#             */
/*   Updated: 2025/10/21 14:07:00 by jow              ###   ########.fr       */
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
	ScavTrap a("apple");
	print_status(a);
	
	ScavTrap b("banana");
	print_status(b);
	a.guardGate();
	a.attack(b.getName());
	b.takeDamage(20);
	print_status(b);

	ScavTrap c(a);
	print_status(c);
	c.takeDamage(10000);

	//test virtual destructor
	ClapTrap *heapScav = new ScavTrap("HeapScav");
	heapScav->attack("random guy");
	delete heapScav;
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