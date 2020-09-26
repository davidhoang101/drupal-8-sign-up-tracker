INTRODUCTION
------------

A simple module that tracks the each activity on entity like insert,
update or delete perform by user.
Logged data will be accessible at https://domain.com/activitytrackinglog

INSTALLATION
------------

Install, and activate the module as you would any other module. As soon as the
module is active, then logs will be recorded in your database.

If you wish to exclude certain entities from being tracking, then you can put
the entity name into provide configuration and their logs will not be tracked.

* Log data will be accssiable at /http://domain.com/activitytrackinglog

CONFIGURATION
-------------

* Configure the user permissions in Administration » People » Permissions:

 - View Activity logs

   The top-level administration categories require this permission to be
   accessible to view the logs.

* Customize the activity tarcking settings in Administration » Configuration »
   system » Activity tracking settings.

MAINTAINERS
-----------

Current maintainers:
 * Vernit Gupta - https://www.drupal.org/u/vernit

REQUIREMENTS
-------------

* Core system and user module must be install
