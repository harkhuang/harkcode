#ifndef _ATOMIC_H
#define _ATOMIC_H

 
typedef struct {
	int counter;
} atomic_t;
 
#define ATOMIC_INIT(i)  { (i) }
 
/**
 * Read atomic variable
 * @param v pointer of type atomic_t
 *
 * Atomically reads the value of @v.
 */
#define atomic_read(v) ((v)->counter)
 
/**
 * Set atomic variable
 * @param v pointer of type atomic_t
 * @param i required value
 */
#define atomic_set(v,i) (((v)->counter) = (i))


 
/**
 * Increment atomic variable
 * @param v pointer of type atomic_t
 *
 * Atomically increments @v by 1.
 */
int atomic_inc( atomic_t *v );
 
/**
 * @brief decrement atomic variable
 * @param v: pointer of type atomic_t
 *
 * Atomically decrements @v by 1.  Note that the guaranteed
 * useful range of an atomic_t is only 24 bits.
 */
int atomic_dec( atomic_t *v );


#endif


