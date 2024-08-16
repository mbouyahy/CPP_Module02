/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:32:03 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/25 11:39:26 by mbouyahy         ###   ########.fr       */
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
        Fixed(const Fixed &f);//copy constructor
        Fixed(void);//default constructor
        ~Fixed(void);//destructor
        Fixed& operator=(const Fixed& other);//A copy assignment operator

        Fixed(const int c_integer);
        Fixed(const float c_fpoint);

        int     getRawBits( void ) const;//eturns the raw value of the fixed-point value
        void    setRawBits( int const raw );//sets the raw value of the fixed-point number
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& other);

#endif