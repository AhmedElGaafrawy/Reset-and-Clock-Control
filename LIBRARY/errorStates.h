/*
 * errorStates.h
 *
 *  Created on	: Mar 31, 2020
 *  Version		: 1.0.0
 *  Author		: Ahmed El-Gaafarwy
 */

#ifndef ERRORSTATES_H_
#define ERRORSTATES_H_

typedef enum
{
	ES_OK,
	ES_NOT_OK,

	ES_NULL_POINTER,

	ES_OUT_OF_RANGE,
	ES_NOT_SELECTED,

	ES_FORCE_TO_PULL_UP,
	ES_FORCE_TO_PULL_DOWN

}ERROR_STATES;

#endif /* ERRORSTATES_H_ */
