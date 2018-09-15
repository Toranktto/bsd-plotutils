/*
 * Copyright (c) 2018 Łukasz Derlatka All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer. 2. Redistributions
 * in binary form must reproduce the above copyright notice, this list of
 * conditions and the following disclaimer in the documentation and/or other
 * materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <plot.h>

PyObject       *
pl_dot_(PyObject * self, PyObject * args)
{
	int		xi, yi, dx, n, *pat;
	register int	i;
	PyObject       *pat_pyseq;
	PyObject       *item;

	if (!PyArg_ParseTuple(args, "iiiO", &xi, &yi, &dx, &pat_pyseq)) {
		return NULL;
	}
	if (!PySequence_Check(pat_pyseq)) {
		PyErr_SetString(PyExc_TypeError, "expected sequence");
		return NULL;
	}
	n = PySequence_Size(pat_pyseq);
	pat = malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		item = PySequence_GetItem(pat_pyseq, i);
		if (!PyInt_Check(item)) {
			free(pat);
			PyErr_SetString(PyExc_TypeError, "expected sequence of integers");
			return NULL;
		}
		pat[i] = (int)PyInt_AsLong(item);
		Py_DECREF(item);
	}

	pl_dot(xi, yi, dx, n, pat);
	free(pat);
	Py_RETURN_NONE;
}
