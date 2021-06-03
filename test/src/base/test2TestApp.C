//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "test2TestApp.h"
#include "test2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
test2TestApp::validParams()
{
  InputParameters params = test2App::validParams();
  return params;
}

test2TestApp::test2TestApp(InputParameters parameters) : MooseApp(parameters)
{
  test2TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

test2TestApp::~test2TestApp() {}

void
test2TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  test2App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"test2TestApp"});
    Registry::registerActionsTo(af, {"test2TestApp"});
  }
}

void
test2TestApp::registerApps()
{
  registerApp(test2App);
  registerApp(test2TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
test2TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  test2TestApp::registerAll(f, af, s);
}
extern "C" void
test2TestApp__registerApps()
{
  test2TestApp::registerApps();
}
