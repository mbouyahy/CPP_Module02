/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:31:44 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/25 11:43:08 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    // std::cout<< "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(const Fixed &f)
{
    // std::cout<< "copy constructor called" << std::endl;
    *this = f;
}

Fixed::Fixed(const int c_integer)
{
    // std::cout<< "Int constructor called" << std::endl;
    this->fixed_point = c_integer * pow(2, this->num_bits);
    // this->fixed_point = c_integer;
}

Fixed::Fixed(const float c_fpoint)
{
    // std::cout<< "Float constructor called" << std::endl;
    float f = (c_fpoint * pow(2, this->num_bits));
    this->fixed_point = int(roundf(f));
}

Fixed:: ~Fixed(void)
{
    // std::cout<< "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" <<std::endl;
    return (this->fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    // std::cout<< "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixed_point = other.getRawBits();
    }
    return (*this);
}

float Fixed::toFloat( void ) const
{
    return(this->fixed_point / pow(2, this->num_bits));
}

int Fixed::toInt( void ) const
{
    return (this->fixed_point / pow(2, this->num_bits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
    out << other.toFloat();
    return (out);
}

Fixed& Fixed::operator+(const Fixed& other)
{
    this->fixed_point = int(roundf((toFloat() + other.toFloat()) * pow(2, this->num_bits)));
    return (*this);
}

Fixed& Fixed::operator-(const Fixed& other)
{
    this->fixed_point = int(roundf((toFloat() - other.toFloat()) * pow(2, this->num_bits)));
    return (*this);
}

Fixed& Fixed::operator*(const Fixed& other)
{
    this->fixed_point = int(roundf((toFloat() * other.toFloat()) * pow(2, this->num_bits)));
    return (*this);
}

Fixed& Fixed::operator/(const Fixed& other)
{
    this->fixed_point = int(roundf((toFloat() / other.toFloat()) * pow(2, this->num_bits)));
    return (*this);
}

Fixed    Fixed::operator++(int)
{
    Fixed save = *this;
    this->fixed_point++;
    return (save);
}

Fixed&    Fixed::operator++()
{
    this->fixed_point++;
    return (*this);
}

Fixed    Fixed::operator--(int)
{
    Fixed save = *this;
    this->fixed_point--;
    return (save);
}

Fixed&    Fixed::operator--()
{
    this->fixed_point--;
    return (*this);
}

bool    Fixed::operator<(const Fixed& other) const
{
    return(fixed_point < other.getRawBits());
}

bool    Fixed::operator>=( const Fixed& other) const
{
    return(fixed_point >= other.getRawBits());
}

bool    Fixed::operator==( const Fixed& other) const
{
    return(fixed_point == other.getRawBits());
}

bool    Fixed::operator!=( const Fixed& other) const
{
    return(fixed_point != other.getRawBits());
}

bool    Fixed::operator>( const Fixed& other) const
{
    return(fixed_point > other.getRawBits());
}

bool    Fixed::operator<=( const Fixed& other) const
{
    return(fixed_point <= other.getRawBits());
}

Fixed const& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if (f1 > f2)
       return (f1);
    else
        return (f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f1 > f2)
       return (f1);
    else
        return (f2);
}

Fixed const& Fixed::min(const Fixed& f1, const Fixed& f2)
{
     if (f1 < f2)
       return (f1);
    else
        return (f2);
}

Fixed& Fixed::min( Fixed& f1,  Fixed& f2)
{
     if (f1 < f2)
       return (f1);
    else
        return (f2);
}
