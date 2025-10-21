/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:01:39 by jow               #+#    #+#             */
/*   Updated: 2025/10/21 13:49:06 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
		std::string name;
		unsigned int hitPt;
		unsigned int energyPt;
		unsigned int atkDmg;
	public:
		static const unsigned int defHitPt = 10;
		static const unsigned int defEnerPt = 10;
		static const unsigned int defAtkDmg = 0;
	
		ClapTrap();
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);
		ClapTrap(const std::string _name);
		
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void);
		unsigned int getHitPt(void);
		unsigned int getEnergyPt(void);
		unsigned int getAtkDmg(void);
		void deductEnergy(void);

		void setHitPoint(unsigned int amount);
		void setEnergyPoint(unsigned int amount);
		void setAtkDmg(unsigned int amount);
} ;

#endif