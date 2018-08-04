# BSD plotutils

Port of ancient plotting utilities and libraries for various languages from 4.3BSD to modern BSD derivatives.
Original libraries were written in C, but there are some wrappers to other languages (See [bindings](libplot/bindings/.) and [examples](libplot/examples/.)):
  * py27plot (Python 2.7)
  * f77plot (FORTRAN 77)

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