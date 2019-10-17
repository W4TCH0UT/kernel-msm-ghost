try {
      Process proc = Runtime.getRuntime().exec(new String[] { "su", "-c", "reboot" });
      proc.waitFor();
         } catch (Exception ex) {
                Log.i(TAG, "Could not reboot", ex);
      }
