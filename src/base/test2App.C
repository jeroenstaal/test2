#include "test2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
test2App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

test2App::test2App(InputParameters parameters) : MooseApp(parameters)
{
  test2App::registerAll(_factory, _action_factory, _syntax);
}

test2App::~test2App() {}

void
test2App::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"test2App"});
  Registry::registerActionsTo(af, {"test2App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
test2App::registerApps()
{
  registerApp(test2App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
test2App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  test2App::registerAll(f, af, s);
}
extern "C" void
test2App__registerApps()
{
  test2App::registerApps();
}
