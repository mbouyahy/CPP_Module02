/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:32:03 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/23 18:37:42 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixed_point;
        static const int num_bits = 8;
    public:
        Fixed(Fixed &f);//copy constructor
        Fixed(void);//default constructor
        ~Fixed(void);//destructor
        Fixed& operator=(const Fixed& other);//copy assignment operator overload

        int getRawBits( void ) const;//returns the raw value of the fixed-point value
        void setRawBits( int const raw );//sets the raw value of the fixed-point number
};

#endif