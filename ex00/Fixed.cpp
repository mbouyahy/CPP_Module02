/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:31:44 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/23 18:49:49 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout<< "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(Fixed &f)
{
    std::cout<< "copy constructor called" << std::endl;
    *this = f;
}

Fixed:: ~Fixed(void)
{
    std::cout<< "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" <<std::endl;
    return (this->fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout<< "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixed_point = other.getRawBits();
    }
    return (*this);
}
