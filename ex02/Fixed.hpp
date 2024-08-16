/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:32:03 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/25 11:41:23 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int num_bits = 8;
    public:
        //Orthodox Canonical Form
        Fixed(const Fixed &f);//copy constructor
        Fixed(void);//default constructor
        ~Fixed(void);//destructor
        Fixed& operator=(const Fixed& other);//A copy assignment operator

        Fixed(const Fixed &f, const Fixed &t);
        Fixed(const int c_integer);
        Fixed(const float c_fpoint);

        //Member Functions
        float   toFloat( void ) const;
        int     toInt( void ) const;

        //Getters and Setters
        int     getRawBits( void ) const;//returns the raw value of the fixed-point value
        void    setRawBits( int const raw );//sets the raw value of the fixed-point number

        //comparison operators
        bool    operator<( const Fixed& other) const;
        bool    operator>=( const Fixed& other) const;
        bool    operator==( const Fixed& other) const;
        bool    operator!=( const Fixed& other) const;
        bool    operator>( const Fixed& other) const;
        bool    operator<=( const Fixed& other) const;

        //arithmetic operators
        Fixed& operator+(const Fixed& other);
        Fixed& operator-(const Fixed& other);
        Fixed& operator*(const Fixed& other);
        Fixed& operator/(const Fixed& other);

        //increment/decrement (post | pre)
        Fixed    operator++(int);
        Fixed&    operator++();
        Fixed    operator--(int);
        Fixed&    operator--();

        //4 static member functions
        static Fixed const& max(const Fixed& f1, const Fixed& f2);
        static Fixed& max( Fixed& fixed_p,  Fixed& fixed_p1);
        static Fixed const& min(const Fixed& f1, const Fixed& f2);
        static Fixed& min( Fixed& fixed_p,  Fixed& fixed_p1);
};

std::ostream& operator<<(std::ostream& o, const Fixed& other);

#endif