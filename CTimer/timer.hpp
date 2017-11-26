/*
 * timer.hpp
 *
 *  Created on: 14.01.2017
 *      Author: Marcin
 */

#ifndef TIMER_HPP_
#define TIMER_HPP_

#define TIMER_RELOAD_VALUE	120

class CTimerModule
{
	unsigned int u32TimerValue;

public:
   void  Init     (void);
   void  Handle   (void);

	void	Reload	(void);
};

#endif /* TIMER_HPP_ */
