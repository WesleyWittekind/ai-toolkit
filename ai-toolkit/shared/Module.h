#pragma once
/*  Author: Wesley Wittekind
*  Date:   5/2/2018
*  Desc:   Generic module interface
*  Credits: Closely modeled on a system developed by the DigiPen game team Redacted for their 
*  Junior project Outlier
*/

class Module
{
public:
  virtual ~Module() = default;

  /*!---------------------------------------------------------
   * \brief Initialize to a valid state if possible, allocate memory, don't interact with other modules
  ----------------------------------------------------------*/
  virtual bool PreInit()      { return true; }

  /*!---------------------------------------------------------
  * \brief Finish initialization so that other modules can access yours during PostInit
  ----------------------------------------------------------*/
  virtual bool Init()         { return true; }
  
  /*!---------------------------------------------------------
  * \brief Link to other modules etc. All modules guarenteed to have finished Init
  ----------------------------------------------------------*/
  virtual bool PostInit()     { return true; }


  /*!---------------------------------------------------------
  * \brief Prepare for shutdown, release resources in other modules, 
  * assume all other modules are still in working order.
  ----------------------------------------------------------*/
  virtual bool PreDestroy()   { return true; }
  
  /*!---------------------------------------------------------
  * \brief Shutdown, this module should have already released any resources in other modules. Any 
  * remaining resources can be cleaned up at this point
  ----------------------------------------------------------*/
  virtual bool Destroy()      { return true; }
  
  /*!---------------------------------------------------------
  * \brief Finalize shutdown and deallocate any remaining memory or resources
  ----------------------------------------------------------*/
  virtual bool PostDestroy()  { return true; }
};
