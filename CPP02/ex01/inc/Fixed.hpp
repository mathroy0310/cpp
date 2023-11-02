/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Fixed.hpp                                         ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 20:48:57 by maroy                                    */
/*   Updated: 2023/10/16 13:03:14 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
# define FIXED_H

class Fixed{

	public:

		//#=- CONSTRUCTOR / DESTRUCTOR -=#//

		// default constructor
		Fixed();
		// constructor with int argument
		Fixed( int const n );
		// constructor with float argument
		Fixed( float const n );
		// by default, copy constructor performs a shallow copy
		Fixed( Fixed const & src );
		// destructor
		~Fixed();

		// #=- OPERATION OVERLOAD -=# //
		
		// opeartor =
		Fixed &	operator=( Fixed const & rhs );
		// operator <<
		friend ostream& operator<<( ostream& os, const Fixed& fixed ) ;

		// #=- GETTER -=# //
		
		int		getRawBits( void ) const;
		// #=- SETTER -=# //

		void	setRawBits( int const raw );
		// #=- OTHER -=# //

		void	printRawBits( void ) const;

		int		toInt( void ) const;
		float	toFloat( void ) const;

	private:

		int					_rawBits;
		static const int	_fractionalBits;
};

#endif // FIXED_H