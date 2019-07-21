#include <ntddk.h>	//类似于iostream.h
void MyDriverUnload(PDRIVER_OBJECT driver);
NTSTATUS DriverEntry(PDRIVER_OBJECT driver, PUNICODE_STRING reg_path)	//类似于main函数，WinMain(),DLL_Entry()
{

	DbgPrint("Hello Word! \r\n");		//调试打印 加载时打印这句话

	driver->DriverUnload = MyDriverUnload;		//指定卸载函数

	return STATUS_SUCCESS;		//返回
}
void MyDriverUnload(PDRIVER_OBJECT driver)
{


	DbgPrint("Sys Unloading....\r\n");	//卸载时打印一句话

}