
#include <cstdio>

#include <sapi/hal.hpp>
#include <sapi/sys/TaskManager.hpp>

int main(int argc, char * argv[]){
	printf("Hello World\n");



	sys::TaskManager taskmgr;
	 int slot;
	 int pid = -1;
	 for (slot = 0; slot < 10; slot++) {
		 pid = taskmgr.get_pid("HelloWorld");
		 if (pid <= -1 || !taskmgr.is_pid_running(sys::Sched::ProcessId((pid_t)pid))) {
			 // try to start separate task
			 pid = sys::Sys::launch(
						 "HelloWorld",
						 sys::Sys::Arguments(""),
						 sys::Appfs::flag_is_orphan
						 );
		 }
	 }

	return 0;
}
