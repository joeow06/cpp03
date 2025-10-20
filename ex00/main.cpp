/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:00:37 by jow               #+#    #+#             */
/*   Updated: 2025/10/21 01:00:06 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void print_status(ClapTrap &a)
{
	std::cout << a.getName() << " | Hit Point: " << a.getHitPt() 
		<< " | Energy Point: " << a.getEnergyPt() << " | Attack Damage: " 
		<< a.getAtkDmg() << std::endl;
}

int main(void)
{
	ClapTrap joe("Joe");
	ClapTrap ren("Ren");
	
	print_status(joe);
	print_status(ren);
	joe.attack("Ren");
	ren.beRepaired(10);
	print_status(joe);
	print_status(ren);

	ClapTrap ben = ren;
	print_status(ben);

	ClapTrap ken("Ken");
	for (int i = 0; i < 10; i++)
		ken.attack("Joe");
	ken.attack("TESTTESTTEST");

	ClapTrap bacon("Bacon");
	for (int i = 0; i < 10; i++)
		bacon.beRepaired(10);
	bacon.beRepaired(100);
}