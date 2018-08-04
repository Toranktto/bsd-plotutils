/*
 * Copyright (c) 2018 Łukasz Derlatka
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <Python.h>
#include <plot.h>

extern PyObject* pl_openpl_(PyObject *self);
extern PyObject* pl_closevt_(PyObject *self);
extern PyObject* pl_openvt_(PyObject *self);
extern PyObject* pl_erase_(PyObject *self);
extern PyObject* pl_label_(PyObject *self, PyObject *args);
extern PyObject* pl_line_(PyObject *self, PyObject *args);
extern PyObject* pl_circle_(PyObject *self, PyObject *args);
extern PyObject* pl_arc_(PyObject *self, PyObject *args);
extern PyObject* pl_move_(PyObject *self, PyObject *args);
extern PyObject* pl_cont_(PyObject *self, PyObject *args);
extern PyObject* pl_point_(PyObject *self, PyObject *args);
extern PyObject* pl_linemod_(PyObject *self, PyObject *args);
extern PyObject* pl_space_(PyObject *self, PyObject *args);
extern PyObject* pl_closepl_(PyObject *self);
extern PyObject* pl_dot_(PyObject *self, PyObject *args);
extern PyObject* pl_box_(PyObject *self, PyObject *args);

static PyMethodDef PlotMethods[] = {
	{ "openpl", (PyCFunction)pl_openpl_, METH_NOARGS, NULL },
	{ "closepl", (PyCFunction)pl_closepl_, METH_NOARGS, NULL },
	{ "openvt", (PyCFunction)pl_openvt_, METH_NOARGS, NULL },
	{ "closevt", (PyCFunction)pl_closevt_, METH_NOARGS, NULL },
	{ "erase", (PyCFunction)pl_erase_, METH_NOARGS, NULL },
	{ "label", (PyCFunction)pl_label_, METH_VARARGS, NULL },
	{ "line", (PyCFunction)pl_line_, METH_VARARGS, NULL },
	{ "circle", (PyCFunction)pl_circle_, METH_VARARGS, NULL },
	{ "arc", (PyCFunction)pl_arc_, METH_VARARGS, NULL },
	{ "move", (PyCFunction)pl_move_, METH_VARARGS, NULL },
	{ "cont", (PyCFunction)pl_cont_, METH_VARARGS, NULL },
	{ "point", (PyCFunction)pl_point_, METH_VARARGS, NULL },
	{ "linemod", (PyCFunction)pl_linemod_, METH_VARARGS, NULL },
	{ "space", (PyCFunction)pl_space_, METH_VARARGS, NULL },
	{ "dot", (PyCFunction)pl_dot_, METH_VARARGS, NULL },
	{ "box", (PyCFunction)pl_box_, METH_VARARGS, NULL },
	{ NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC
initpy27plot(void)
{
	Py_InitModule("py27plot", PlotMethods);
}
