# BSD plotutils

Port of ancient plotting utilities and libraries (for C and FORTRAN 77) from 4.3BSD to modern BSD derivatives.

## Installation

```
# make && make install && make cleandir
```

```
lukasz@Lukasz-komputer:~ % cat > plot
1.0 5.0
2.0 10.0
3.0 5.0
4.0 10.0
5.0 5.0
6.0 10.0
7.0 5.0 
8.0 10.0
9.0 5.0
lukasz@Lukasz-komputer:~ % spline < plot | graph -g1 | dumbplot
    ***************************************************************************** 
    *                                                                           * 
    *                                                                           * 
    *                                                                           * 
    *                                                                           * 
    *                                                                           * 
    **           ***             ***             **             ***            ** 
    *           *  *             * *            * *             *  *            * 
    *           *   *           *   *          *   *           *    *           * 
    *          *     *         *    *          *    *         *     *           * 
    *          *     *         *    *          *    *         *      *          * 
    *         *      *         *     *        *     *         *      *          * 
    **        *       *        *      *       *      *       *       *         ** 
    *         *        *      *       *      *       *       *        *         * 
    *        *         *      *       *      *        *      *        *         * 
    *        *         *     *        *      *        *      *         *        * 
    *       *          *     *         *     *        *     *          *        * 
    **      *           *    *         *    *          *   *           *       ** 
    *       *           *   *           *  *           *   *           *        * 
    *       *           *   *           *  *           *   *            *       * 
    *      *             ***             **             ***                     * 
    *                                                                           * 
    *                                                                           * 
    ***************************************************************************** 
    0 -x- 10  4 -y- 12                                                            

```