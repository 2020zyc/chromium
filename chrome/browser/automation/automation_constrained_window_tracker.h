// Copyright (c) 2006-2008 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_AUTOMATION_AUTOMATION_CONSTRAINED_WINDOW_TRACKER_H__
#define CHROME_BROWSER_AUTOMATION_AUTOMATION_CONSTRAINED_WINDOW_TRACKER_H__

#include "chrome/browser/automation/automation_resource_tracker.h"
#include "chrome/browser/tab_contents/constrained_window.h"

class AutomationConstrainedWindowTracker
  : public AutomationResourceTracker<ConstrainedWindow*> {
public:
  AutomationConstrainedWindowTracker(IPC::Message::Sender* automation)
      : AutomationResourceTracker(automation) {}

  virtual ~AutomationConstrainedWindowTracker() {
  }

  virtual void AddObserver(ConstrainedWindow* resource) {
    registrar_.Add(this, NotificationType::CWINDOW_CLOSED,
                   Source<ConstrainedWindow>(resource));
  }

  virtual void RemoveObserver(ConstrainedWindow* resource) {
    registrar_.Remove(this, NotificationType::CWINDOW_CLOSED,
                      Source<ConstrainedWindow>(resource));
  }
};

#endif  // CHROME_BROWSER_AUTOMATION_AUTOMATION_CONSTRAINED_WINDOW_TRACKER_H__
